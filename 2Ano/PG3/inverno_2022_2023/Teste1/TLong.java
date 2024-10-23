import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.function.Predicate;

public class TLong extends Transaction implements Composition{
    private final List<Transaction> Transactions= new ArrayList<>();

    public TLong(String name){
        super(name);
    }

    public boolean isCompensable(){
        return true;
    }

    public Iterator<Transaction> iterator(){
        return Transactions.iterator();
    }

    public TLong append(Transaction t) throws TransactionException {
        if(!t.isCompensable()) throw new TransactionException("Transaction not compensable", t);
        if(find(n -> n.equals(t.getName()))) throw new TransactionException("Duplicate transaction", t);
        this.Transactions.add(t);
        return this;
    }

    public boolean find(Predicate<String> pred){
        for(Transaction t: Transactions){
            if(t.find(pred)) return true;
        }
        return false;
    }

    public String getDescription(String prefix){
        StringBuilder s = new StringBuilder(super.getDescription(prefix));
        for (Transaction t : Transactions) {
            s.append("\n").append(t.getDescription("  " + prefix));
//            s.append("\n").append("aaa");
        }
        return s.toString();
    }

    public String compensationToString() {
        return null;
    }


    public static void main(String[] args) {
        TLong travel = new TLong("Viagem");
        try {
            TLong flight= new TLong("Marcar voo");
            TShort book = new TShort("Reservar voo", "Cancelar voo"),
                    pay = new TShort("Pagamento voo", "Devolver pagamento voo");
            flight.append(book).append( pay );
            TLong hotel = new TLong("Marcar hotel");
            hotel.append( new TShort("Reservar hotel", "Cancelar hotel") )
                    .append( new TShort("Pagamento estadia","Devolver pagamento estadia"));

            travel.append( flight ).append( hotel );
            travel.append( book);
        }
        catch ( TransactionException e ) {
            System.out.println( e.getMessage() );
            System.out.println( e.getTransaction() );
        }
        if( ! travel.find(s-> s.equals("Viagem")) &&
                travel.find(s-> s.equals("Reservar hotel")) &&
                travel.find(s-> s.equals("Cancelar voo")) )
            System.out.println( "Find is CORRECT" );

        System.out.println( travel.getDescription("-> ") );

        System.out.println( travel.compensationToString() );

    }
}
