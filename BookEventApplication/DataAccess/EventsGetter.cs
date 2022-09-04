using BusinessObjects;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataAccess
{
    public class EventsGetter
    {
        public List<EventsBO> GetEvents(int id)
        {
            
            BookEventContext bookEventContext = new BookEventContext();
            bookEventContext.Database.Log = Console.Write;
            var events = from c in bookEventContext.EventsBOs
                         where c.EventsCreatedById == id
                         orderby c.DateOfTheEvent descending
                         select c;
            var eve = events.ToList();

            return eve;

        }
        public List<EventsBO> GetMyEvents(int id)
        {
            BookEventContext bookEventContext = new BookEventContext();
            bookEventContext.Database.Log = Console.Write;
            var events = from c in bookEventContext.EventsBOs
                         where c.EventsCreatedById == id
                         select c;
            var eve = events.ToList();

            return eve;


        }
        public List<EventsBO> GetThisEvents(int id)
        {
            BookEventContext bookEventContext = new BookEventContext();
            bookEventContext.Database.Log = Console.Write;
            var events = from c in bookEventContext.EventsBOs
                         where c.EventId == id
                         select c;
            var eve = events.ToList();

            return eve;


        }
        public  List<EventsBO> GetAllEvents()
        {
            BookEventContext bookEventContext = new BookEventContext();
            bookEventContext.Database.Log = Console.Write;
            IOrderedQueryable<EventsBO> events = from e in bookEventContext.EventsBOs orderby e.DateOfTheEvent select e;
            var eve = events.ToList();

            return eve;

        }
    }
}
