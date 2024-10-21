public abstract class Page {
    private final String tag, title;
    private final Paragraph[] paragraphs;

    protected Page(String tag, String title, Paragraph ... pgraphs) {
        this.tag = tag;
        this.title = title;
        this.paragraphs = pgraphs;
    }

    public final String getTitle() {
        return this.title;
    }

    public abstract String renderMenu();

    public String render() {
        StringBuilder p = new StringBuilder("<" + this.tag + ">\n" + "\t<title>" + this.title + "</title>\n" + this.renderMenu() + "\n");
        for (Paragraph paragraph : paragraphs) {
            p.append("\t").append(paragraph.getContent()).append("\n");
        }
        p.append("</").append(this.tag).append(">");

        return p.toString();
    }

    public Page findFirstPage(String searchedText) {
        if(this.title.contains(searchedText) ) {
            return this;
        }
        for (Paragraph p : paragraphs) {
            if (p.containText(searchedText)) {
                return this;
            }
        }
        return null;
    }

    public static void main(String[] args) {
        Paragraph txt = new TextParagraph( "1ª imagem.");
        Paragraph img= new ImageParagraph( "image1.jpg" );
        SimplePage pg= new SimplePage( "1ª página", txt, img );
        System.out.println ( pg.renderMenu() );
        System.out.println( pg.render() );
    }
}
