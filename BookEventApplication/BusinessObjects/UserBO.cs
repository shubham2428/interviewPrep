using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BusinessObjects
{
   
    public class UserBO
    {
        [Key]
        [Display(Name = "UserID")]
        [Required(ErrorMessage = "User ID is Required")]
        public int UserID { get; set; }

        [Display(Name = "UserName")]
        [Required(ErrorMessage = "User Name is Required")]
        public string UserName { get; set; }

        [Display(Name = "Password")]
        [Required(ErrorMessage = "Password is Required")]
        public string Password { get; set; }

        [Display(Name = "EmailId")]
        [Required(ErrorMessage = "EmailId is Required")]
        public string EmailId{ get; set; }

        [Display(Name = "TypeOfUser")]
        [Required(ErrorMessage = "TypeOfUser is Required")]
        public string TypeOfUser{ get; set; }



    }
}
