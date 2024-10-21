public class SimplePage extends Page {
    public SimplePage(String title, Paragraph ... pgraphs) {
        super("page", title, pgraphs);
    }

    public String renderMenu() {
        return "\t<menu><item>voltar</item></menu>";
    }
}
