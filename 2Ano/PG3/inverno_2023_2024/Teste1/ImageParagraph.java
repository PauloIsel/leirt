public class ImageParagraph implements Paragraph {
    private final String image;

    public ImageParagraph(String image) {
        this.image = image;
    }

    public String getContent() {
        return "<img src = \"" + image + "\"/>";
    }

    public boolean containText(String word) { return false;}

    public static void main(String[] args) {
        Paragraph img= new ImageParagraph( "image1.jpg" );
        System.out.println( img.getContent() );
    }
}
