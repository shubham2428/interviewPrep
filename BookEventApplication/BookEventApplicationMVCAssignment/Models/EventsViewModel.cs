using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace BookEventApplicationMVCAssignment.Models
{
    public class EventsViewModel
    {
        public string EventId { get; set; }

       
        public string EventsCreatedByName { get; set; }

        public string NameOfTheEvent { get; set; }

        public string TitleOfTheBook { get; set; }

        public DateTime DateOfTheEvent { get; set; }

        public string TypeOfEvent { get; set; }

        public string Location { get; set; }

        public DateTime StartTime { get; set; }

        public string Duration { get; set; }

        public string AddPeople { get; set; }

        public string Description { get; set; }
    }
}