import java.util.function.Predicate;

public interface Composition extends Iterable<Transaction> {
    boolean find(Predicate<String> pred);
    Composition append(Transaction t) throws TransactionException;
}
