using BusinessObjects;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataAccess
{
    public class EventsInvitedTo
    {
        public IEnumerable<EventsBO> EventsInvited(string Email)
        {
            BookEventContext bookEventContext = new BookEventContext();
            bookEventContext.Database.Log = Console.Write;
            var results = (from a in bookEventContext.EventsBOs select a).ToList();
           
            var events = results.Where(c => c.AddPeople.Split(',').Contains(Email)).Select(c => c);
            return events;
        }


    }
}
