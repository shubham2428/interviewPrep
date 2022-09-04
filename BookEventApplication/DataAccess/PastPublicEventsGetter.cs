using BusinessObjects;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataAccess
{
    public class PastPublicEventsGetter
    {
        public List<EventsBO> GetPastEvents()
        {
            BookEventContext bookEventContext = new BookEventContext();
            bookEventContext.Database.Log = Console.Write;
            var events = from c in bookEventContext.EventsBOs
                         where c.DateOfTheEvent < DateTime.Now && c.TypeOfEvent=="Public"
                         select c;
            var eve = events.ToList();

            return eve;


        }
    }
   
}
