import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.function.Predicate;

public abstract class TLong extends Transaction implements Composition{
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
}
