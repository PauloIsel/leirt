import java.util.function.Predicate;

public abstract class Transaction {
    private final String name;

    protected Transaction(String name) {
        this.name = name;
    }

    public final String getName() {
        return this.name;
    }

    public abstract boolean isCompensable();
    public abstract String compensationToString();

    public String getDescription(String prefix) {
        return prefix + "\"" + this.getName() + "\"";
    }

    public boolean find(Predicate<String> pred){ return pred.test(name); }
    public final String toString() { return name; }

    public static void main(String[] args) {
        Transaction t = new Transaction("t1") {
            @Override
            public boolean isCompensable() {
                return false;
            }

            @Override
            public String compensationToString() {
                return null;
            }
        };
        System.out.println(t.getDescription("prefix"));
    }
}


