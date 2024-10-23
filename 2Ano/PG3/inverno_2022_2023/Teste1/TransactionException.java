public class TransactionException extends Exception {
    private final Transaction transaction;

    public TransactionException(String msg, Transaction t) {
        super(msg);
        this.transaction = t;
    }

    public TransactionException() {
        super("Invalid transaction");
        this.transaction = null;
    }

    public Transaction getTransaction() {
        return this.transaction;
    }
}
