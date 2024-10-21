
import java.util.List;
import java.util.ArrayList;
import java.util.Iterator;

public class FolderPage extends Page implements Iterable<Page> {
    private final List<Page> pages = new ArrayList<>();

    public FolderPage(int titleId, Paragraph ... pgraphs) {
        super("folder", "Pasta" + titleId, pgraphs);
    }

    public Page findFirstPage(String searchedText) {
        if(super.findFirstPage(searchedText) != null) return this;
        for (Page p : pages) {
            Page searchedPage = p.findFirstPage(searchedText);
            if (searchedPage != null) return searchedPage;
        }
        return null;
    }

    public FolderPage addPage(Page page) throws CmsException {
        for (Page p : pages) {
            if(p.getTitle().equals(page.getTitle())) throw new CmsException(p);
        }
        this.pages.add(page);
        return this;
    }

    public String renderMenu() {
        StringBuilder result = new StringBuilder("\t<menu>\n");
        for(Page p : pages) {
            result.append("\t\t<item>").append(p.getTitle()).append("</item>\n");
        }
        result.append("\t</menu>");
        return result.toString();
    }

    public Iterator<Page> iterator() {
        return this.pages.iterator();
    }
}
