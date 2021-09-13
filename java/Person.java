public class Person {
    int age;
    String name;
    String sex;

    public void study() {
        System.out.println("studying");
    }

    public void addAge() {
        this.age += 2;
    }

    public void showAge() {
        System.out.println(this.age);
    }

    public void printVarArgs(String... args) {
        for (int i = 0; i < args.length; ++i) {
            System.out.println(args[i]);
        }
    }

    public void printVarArgsInt(int... args) {
        for (int i = 0; i < args.length; ++i) {
            System.out.println(args[i]);
        }
    }
}
