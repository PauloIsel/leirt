public class TextParagraph implements Paragraph{
    private final String Text;

    public TextParagraph(String Text){
        this.Text = Text;
    }

    public String getContent() {
        return "<txt>" + this.Text + "</txt>";
    }
    public boolean containText(String word) {
        return this.Text.contains(word);
    }

    public static void main(String[] args) {
        Paragraph txt = new TextParagraph("1ª imagem.");
        System.out.println(txt.getContent());
    }
}
