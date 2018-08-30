using System.Collections.Generic;
using System.ComponentModel;
using System.ComponentModel.DataAnnotations;

namespace Example.Models
{
    public class FormModel
    {
        [Required, Display(Name="Email Address")]
        public string Email { get; set; }
        [Required, DataType(DataType.Password), StringLength(32, MinimumLength = 6)]
        public string Password { get; set; }
        [Display(Name="Awesome?")]
        public bool Check { get; set; }
    }
}
