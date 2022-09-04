using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BusinessObjects
{
    public class EventsBO
    {
        [Key]
        [Display(Name = "EventId")]
        [Required(ErrorMessage = "Event Id is required for creation")]
        public int EventId { get; set; }

        [ForeignKey("UserBO")]
        [Display(Name = "EventCreatedById")]
        public int EventsCreatedById { get; set; }

      
        [Display(Name = "EventCreatedByName")]
        public string EventsCreatedByName{ get; set; }

        [Display(Name = "Name of the Event")]
        [Required(ErrorMessage = "Event Name is Required")]
        public string NameOfTheEvent { get; set; }

        [Display(Name = "Title of the Book")]
        [Required(ErrorMessage = "Book Title  is Required")]
        public string TitleOfTheBook { get; set; }

        [Display(Name = "DateOfTheEvent")]
        [Required(ErrorMessage = "Event of the date is Required")]
        public DateTime DateOfTheEvent { get; set; }

        [Display(Name = "Location")]
        [Required(ErrorMessage = "Location is Required")]
        public string Location { get; set; }

        [Display(Name = "TypeOfEvent")]
        public string TypeOfEvent{ get; set; }

        public DateTime StartTime { get; set; }

        public string Duration { get; set; }

        public string AddPeople { get; set; }

        public string Description { get; set; }

        public virtual UserBO UserBO { get; set; }
        
    }
}
