import java.util.function.Predicate;

public class TShort extends Transaction {
    public final TCompensation compensation;

    public TShort(String name, TCompensation tc) {
        super(name);
        this.compensation = tc;
    }

    public TShort(String name, String nameCompensation) {
        this(name, new TCompensation(nameCompensation));
    }

    public boolean isCompensable() {
        return true;
    }

    @Override
    public String compensationToString() {
        return this.compensation.getDescription("");
    }

    public String getDescription(String prefix) {
        return super.getDescription(prefix) + " - " + this.compensationToString();
    }

    @Override
    public boolean find(Predicate<String> pred) {
        return (pred.test(this.getName() ) || pred.test(this.compensation.getName()));
    }

    public static void main(String[] args) {
        TCompensation cancel = new TCompensation("Cancelar voo");

        TShort book=new TShort("Reservar voo",cancel);
        System.out.println( book ) ;
        System.out.println( book.getDescription(" >>" ));
        System.out.println( book.isCompensable());

        System.out.println( book.find( s -> s.contains("Reserva")));
        System.out.println( book.find( s -> s.contains("Cancela")));

        TShort pay = new TShort("Pagamento voo", "Devolver pagamento voo");
        System.out.println( pay.getDescription(""));
        System.out.println( pay.compensation );

    }
}
