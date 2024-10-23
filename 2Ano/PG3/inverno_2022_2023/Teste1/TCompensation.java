public class TCompensation extends Transaction {

    public TCompensation(String name) {
        super(name);
    }

    public boolean isCompensable() {
        return false;
    }

    public String compensationToString() {
        throw new UnsupportedOperationException();
    }

    public static void main(String[] args) {
        TCompensation cancel = new TCompensation("Cancelar voo");
        System.out.println( cancel.getDescription("->") );
        System.out.println( cancel.isCompensable());
    }
}
