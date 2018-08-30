using System.ComponentModel.DataAnnotations;

namespace Models
{
    public class Student
    {
        [Required, Display(Name="First Name")]
        public string FirstName { get; set; }
        [Required, Display(Name="Last Name")]

        public string LastName { get; set; }
        [Required, DataType(DataType.Password)]
        [Display(Name="Password")]

        public string Password { get; set; }
        
        public bool Subscribe { get; set; }
    }
}