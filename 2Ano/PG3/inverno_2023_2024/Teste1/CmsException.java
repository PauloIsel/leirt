import java.lang.Exception;

public class CmsException extends Exception{
  public CmsException(Page p) { super("Duplicate page: \"" + p.getTitle() + '"'); };
  public CmsException(String msg) { super(msg); };
}
