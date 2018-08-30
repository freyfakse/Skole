using System.ComponentModel.DataAnnotations;

namespace Models
{
    public class Article
    {
        public Article() {}

        public Article(string title, string summary, string image)
        {
            this.Title = title;
            this.Summary = summary;
            this.Image = image;

            // Just set a common article body for this example
            this.Body = "Body of the article would go here.";
        }

        public int Id { get; set; }

        [Required]
        public string Title { get; set; }

        [Required]
        public string Summary { get; set; }

        [Required]
        public string Body { get; set; }

        [DataType(DataType.ImageUrl)]
        public string Image { get; set; }
    }
}
