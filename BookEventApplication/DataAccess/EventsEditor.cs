using BusinessObjects;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataAccess
{
    public class EventsEditor
    {
        public EventsBO EventsEditing(int id)
        {
            BookEventContext bookEventContext = new BookEventContext();
            bookEventContext.Database.Log = Console.Write;
            var events = from c in bookEventContext.EventsBOs
                         where c.EventId == id
                         select c;
            var eve = events.FirstOrDefault();

            return eve;
        }
    }
}
