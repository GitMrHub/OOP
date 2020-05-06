using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{

    class Car
    {

        protected string name;
        public string Name { get { return name; } set { name = value; } }

        protected string mark;
        public string Mark { get { return mark; } set { mark = value; } }

        protected int year;
        public int Year { get { return year; } set { year = value; } }

        protected int price;
        public int Price { get { return price; } set { price = value; } }

        public Car() : this("AAAAAA", "LADA", 1978, 3000) { }

        public Car(string name_, string mark_, int year_, int price_)
        {

            name = name_;
            mark = mark_;
            year = year_;
            price = price_;
        }

        override public string ToString()
        {
            return name + " " + mark + " " + year + " " + price + "$ "; ;
        }

        virtual public void print()
        {
            Console.Write(ToString());
        }

        public void shortInfo()
        {
            Console.Write(name);
        }

        public override int GetHashCode()
        {
            return (mark.Length + name.Length + year + price);
        }

        public override bool Equals(object obj)
        {
            if (obj == null)
                return false;
            Car p = obj as Car;
            if (p as Car == null)
                return false;
            return p.name == this.name && p.mark == this.mark && p.year == this.year && p.price == this.price;
        }

        public static bool operator ==(Car p1, Car p2)
        {
            return p1.Equals(p2);
        }
        public static bool operator !=(Car p1, Car p2)
        {
            return !p1.Equals(p2);
        }
    }



    class Transportation : Car, IComparable
    {
        int price_2;
        public int Price_2 { get { return price_2; } set { price_2 = value; } }
        int time;
        public int Time { get { return time; } set { time = value; } }
        protected string number;
        public string Number { get { return number; } set { number = value; } }

        DateTime date;

        public Transportation() : base()
        {
            price_2 = 100;
            time = 30;
            number = "AA1111BB";

        }
        public Transportation(int price_, int time_, string number_, string name, string mark, int yaer, int price, int y, int m, int d) : base(name, mark, yaer, price)
        {
            price_2 = price_;
            time = time_;
            number = number_;
            //date = new DateTime(y, m, d);
        }

        override public string ToString()
        {
            return base.ToString() + " " + price_2 + "$ (" + time + ")min " + number + " " + date.ToString();
        }

        override public void print()
        {
            Console.Write(ToString());
        }

        new public void shortInfo()
        {
            Console.Write(number + " of " + name);
        }

        public static Transportation operator +(Transportation c1, Transportation c2)
        {
            if (c1 as Car != c2 as Car)
                return new Transportation
                {
                    price_2 = c1.price_2 + c2.price_2,
                    time = c1.time + c2.time,
                    number = c1.number,
                    name = c1.name,
                    mark = c1.mark,
                    year = c1.year,
                    price = c1.price,
                    date = c1.date
                };
            return c1;
        }

        public int CompareTo(object obj)
        {
            if (obj == null)
                return 1;
            Transportation c = obj as Transportation;
            if (c as Transportation == null)
                return 1;
            return (this.price_2 - c.price_2);
        }

        public static bool operator <(Transportation c1, Transportation c2)
        {
            return (c1.CompareTo(c2) < 0);
        }
        public static bool operator >(Transportation c1, Transportation c2)
        {
            return (c1.CompareTo(c2) > 0);
        }
    }

    class Rental
    {
        protected string name_2;
        public string Name_2 { get { return name_2; } set { name_2 = value; } }
        Transportation[] array;
        int num;

        public Rental()
        {
            name_2 = "KPI";
            num = 5;
            array = new Transportation[num];
            for (int i = 0; i < num; i++)
            {
                Random rand = new Random();
                array[i] = new Transportation(rand.Next(900), rand.Next(867), "BB4465BB", "GAZ", "BUSUC", 1975, 400, 2019, rand.Next(12), rand.Next(30));
            }
        }

        public Transportation this[int number]
        {
            get
            {
                if (number < num && number >= 0) return array[number];
                else return array[0];
            }
        }

    }

    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Car c: ");
            Car c = new Car("CCCCC", "AUDI", 2011, 5000);
            c.print();
            Console.Write("\nCopy of c: ");
            Car c_copy = c;
            c_copy.print();

            Transportation t1 = new Transportation(250, 10, "AA1010CC", "BBBBB", "Shkoda", 1999, 1000, 2019, 12, 11);
            Transportation t2 = new Transportation(150, 45, "BH6584CA", "CCCCC", "TOYOTA", 2015, 2000, 2019, 12, 13);
            Console.WriteLine("\n\nT1: " + t1.ToString() + "\nT2: " + t2.ToString());
            Console.Write("Enter a new price for T2: ");
            t2.Price = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("t1>t2: " + (t1 > t2).ToString());

            Transportation t3 = new Transportation();
            Console.Write("\nDefault Transportation t3: " + t3.ToString());
            t3 = t1 + t2;
            Console.Write("\nt3=t1+t2: ");
            t3.print();

            Rental r = new Rental();
            Console.Write("\n\nIndexator: Enter a number\n");
            int i = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Rental[" + i.ToString() + "] : " + r[i].ToString());

            Car[] arr = new Car[2];
            arr[0] = c;
            arr[1] = t1;
            Console.Write("\n\narr[0] is Car, arr[1] is Transportation\n");
            Console.WriteLine("Virtual function:");
            Console.Write("arr[0]:"); arr[0].print();
            Console.Write("\narr[1]:"); arr[1].print();
            Console.WriteLine("\nNon virtual function function:");
            Console.Write("arr[0]:"); arr[0].shortInfo();
            Console.Write("\narr[1]:"); arr[1].shortInfo();

            Console.ReadLine();
        }
    }
}