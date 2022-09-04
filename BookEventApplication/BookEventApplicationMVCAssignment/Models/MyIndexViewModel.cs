using BusinessObjects;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace BookEventApplicationMVCAssignment.Models
{
    public class MyIndexViewModel
    {
        public List<EventsBO> FutureEvents { get; set; }

        public List<EventsBO> PastEvents { get; set; }

    }
}