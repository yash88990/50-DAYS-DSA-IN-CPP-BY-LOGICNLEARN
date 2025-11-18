// ===============================================================
//                 OOP CONCEPTS IN JAVA (ALL-IN-ONE)
// ===============================================================

class Car {
    String brand;
    int speed;

    void drive() {
        System.out.println(brand + " is running at speed: " + speed + " km/h.");
    }
}

// ===============================================================
//                       ENCAPSULATION
// ===============================================================

class BankAccount {
    private int balance;

    public void setBalance(int b) {
        if (b >= 0) balance = b;
        else System.out.println("Invalid Balance");
    }

    public int getBalance() {
        return balance;
    }
}

// ===============================================================
//                       ABSTRACTION
// ===============================================================

abstract class AnimalA {
    abstract void makeSound();

    void sleep() {
        System.out.println("Animal is sleeping...");
    }
}

class DogA extends AnimalA {
    @Override
    void makeSound() {
        System.out.println("Dog barks!!!...");
    }
}

class CatA extends AnimalA {
    @Override
    void makeSound() {
        System.out.println("Cat meows...");
    }
}

// ===============================================================
//                       INHERITANCE
// ===============================================================

// --------------------- Single Inheritance ----------------------

class Animal {
    void sleep() {
        System.out.println("Animal is sleeping...");
    }

    void eat() {
        System.out.println("Animal is eating...");
    }
}

class Dog extends Animal {
    void makeSound() {
        System.out.println("Dog barks!!!...");
    }
}

// ------------------- Multiple Inheritance (NOT in Java) --------
// Java does NOT support:
// class Child extends Father, Mother  ❌
//
// ALTERNATIVE: Use interfaces ✔

interface Father {
    void farming();
}

interface Mother {
    void cooking();
}

class Child implements Father, Mother {
    public void farming() {
        System.out.println("Farming from father...");
    }

    public void cooking() {
        System.out.println("Cooking from mother...");
    }

    void study() {
        System.out.println("Child is studying...");
    }
}

// ------------------------ Multilevel Inheritance ---------------

class Animal2 {
    void eat() {
        System.out.println("Animal eats...");
    }
}

class Mammal extends Animal2 {
    void walk() {
        System.out.println("Mammal walks...");
    }
}

class Human extends Mammal {
    void speak() {
        System.out.println("Human speaks...");
    }
}

// ---------------------- Hierarchical Inheritance ----------------

class Father2 {
    void walk() {
        System.out.println("Walking property from father...");
    }
}

class Son extends Father2 {
    void drive() {
        System.out.println("Son is driving...");
    }
}

class Daughter extends Father2 {
    void dance() {
        System.out.println("Daughter is dancing...");
    }
}

// ---------------------- Hybrid Inheritance (not via classes) ---
// Java alternative: Many Interfaces + Classes

class FriendOfDaughter extends Daughter {
    void sing() {
        System.out.println("Friend can sing...");
    }
}

// ===============================================================
//                       POLYMORPHISM
// ===============================================================

// ---------- 1. Compile-Time Polymorphism (Method Overloading) -----

class Print {
    void show(int x) {
        System.out.println("Integer: " + x);
    }

    void show(String s) {
        System.out.println("String: " + s);
    }

    void show(double d) {
        System.out.println("Double: " + d);
    }
}

// ---------- 2. Operator Overloading (NOT in Java) ------------------
//
// C++ allows: c3 = c1 + c2
// Java does NOT support operator overloading except '+'' for strings.
//
// ALTERNATIVE: Use methods ✔

class Complex {
    int real, img;

    Complex(int r, int i) {
        real = r;
        img = i;
    }

    Complex add(Complex c) {
        return new Complex(real + c.real, img + c.img);
    }

    void display() {
        System.out.println(real + " + " + img + "i");
    }
}

// ---------- 3. Runtime Polymorphism (Method Overriding) ------------

class AnimalP {
    void sound() {
        System.out.println("Some animal sound...");
    }
}

class DogP extends AnimalP {
    @Override
    void sound() {
        System.out.println("Dog barks!!!...");
    }
}

class CatP extends AnimalP {
    @Override
    void sound() {
        System.out.println("Cat meow...");
    }
}

// ===============================================================
//                       CONSTRUCTORS
// ===============================================================

class Student {
    String name;
    int roll;

    Student() {
        name = "not assigned";
        roll = 0;
        System.out.println("Inside default constructor");
    }

    Student(String n, int r) {
        name = n;
        roll = r;
        System.out.println("Inside parameterized constructor");
    }

    Student(Student s) {
        this.name = s.name;
        this.roll = s.roll;
        System.out.println("Inside copy constructor");
    }

    void display() {
        System.out.println("Name: " + name + ", Roll: " + roll);
    }
}

// ===============================================================
//                       DESTRUCTOR (NOT IN JAVA)
// ===============================================================
//
// Java does NOT have destructors.
// Java uses automatic Garbage Collection.
// finalize() is deprecated and not reliable.

// ===============================================================
//                       FRIEND FUNCTION (NOT IN JAVA)
// ===============================================================
//
// ALTERNATIVE: use getters
//
// ===============================================================
//                       MAIN FUNCTION
// ===============================================================

public class Main {
    public static void main(String[] args) {

        // ---------------- CLASS & OBJECT ----------------
        Car car1 = new Car();
        car1.brand = "Tesla";
        car1.speed = 240;
        car1.drive();

        // ---------------- ENCAPSULATION ----------------
        BankAccount acc = new BankAccount();
        acc.setBalance(3000);
        System.out.println("Balance: " + acc.getBalance());

        // ---------------- ABSTRACTION ------------------
        DogA d = new DogA();
        d.makeSound();
        d.sleep();

        // ---------------- INHERITANCE ------------------
        Dog dog = new Dog();
        dog.eat();
        dog.sleep();
        dog.makeSound();

        // Multiple via interfaces
        Child child = new Child();
        child.farming();
        child.cooking();
        child.study();

        // Multilevel
        Human h = new Human();
        h.eat();
        h.walk();
        h.speak();

        // Hierarchical
        Son s = new Son();
        s.walk();
        s.drive();

        Daughter dt = new Daughter();
        dt.walk();
        dt.dance();

        // Hybrid
        FriendOfDaughter f = new FriendOfDaughter();
        f.walk();
        f.dance();
        f.sing();

        // ---------------- POLYMORPHISM -----------------

        // Method overloading
        Print p = new Print();
        p.show("Yash");
        p.show(22);
        p.show(8.7);

        // "Operator overloading" alternative
        Complex c1 = new Complex(2, 3);
        Complex c2 = new Complex(4, 6);
        Complex sum = c1.add(c2);
        sum.display();

        // Runtime polymorphism
        AnimalP a;

        a = new DogP();
        a.sound();

        a = new CatP();
        a.sound();

        // ---------------- CONSTRUCTOR ------------------
        Student st1 = new Student();
        st1.display();

        Student st2 = new Student("Yash", 1);
        st2.display();

        Student st3 = new Student(st2);
        st3.display();
    }
}
