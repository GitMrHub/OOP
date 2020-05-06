using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cp3_17
{
    class Vegetable
    {
        protected string name;
        public string Name { get { return name; } set { name = value; } }
        protected string country;
        public string Country { get { return country; } set { country = value; } }

        protected int season;
        public int Season { get { return season; } set { season = value; } }
        public Vegetable() : this("Tomato", "Ukraine", 1) { }
        public Vegetable(string name_, string country_, int season_)
        {
            name = name_;
            country = country_;
            season = season_;
        }

        override public string ToString()
        {
            return name + " " + country + " " + season; ;
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
            return (country.Length + name.Length + season);
        }

        public override bool Equals(object obj)
        {
            if (obj == null)
                return false;
            Vegetable p = obj as Vegetable;
            if (p as Vegetable == null)
                return false;
            return p.name == this.name && p.country == this.country && p.season == this.season;
        }

        public static bool operator ==(Vegetable p1, Vegetable p2)
        {
            return p1.Equals(p2);
        }
        public static bool operator !=(Vegetable p1, Vegetable p2)
        {
            return !p1.Equals(p2);
        }
    }

    class Consignment : Vegetable, IComparable
    {
        int price;
        public int Price { get { return price; } set { price = value; } }
        int number;
        public int Number { get { return number; } set { number = value; } }

        DateTime date;

        public Consignment() : base()
        {
            price = 100;
            number = 200;
        }
        public Consignment(int price_, int number_, string name, string country, int season, int y, int m, int d) : base(name, country, season)
        {
            price = price_;
            number = number_;
            date = new DateTime(y, m, d);
        }

        override public string ToString()
        {
            return base.ToString() + " " + price + "$ (" + number + ") of " + date.ToString();
        }

        override public void print()
        {
            Console.Write(ToString());
        }

        new public void shortInfo()
        {
            Console.Write(number + " of " + name);
        }

        public static Consignment operator +(Consignment c1, Consignment c2)
        {
            if (c1 as Vegetable == c2 as Vegetable)
                return new Consignment
                {
                    price = c1.price + c2.price,
                    number = c1.number + c2.number,
                    name = c1.name,
                    country = c1.country,
                    season = c1.season,
                    date = c1.date
                };
            return c1;
        }

        public int CompareTo(object obj)
        {
            if (obj == null)
                return 1;
            Consignment c = obj as Consignment;
            if (c as Consignment == null)
                return 1;
            return (this.price - c.price);
        }

        public static bool operator <(Consignment c1, Consignment c2)
        {
            return (c1.CompareTo(c2) < 0);
        }
        public static bool operator >(Consignment c1, Consignment c2)
        {
            return (c1.CompareTo(c2) > 0);
        }
    }

    class Warehouse
    {
        int rental_price;
        Consignment[] array;
        int num;

        public Warehouse()
        {
            rental_price = 1000;
            num = 5;
            array = new Consignment[num];
            for (int i = 0; i < num; i++)
            {
                Random rand = new Random();
                array[i] = new Consignment(rand.Next(900), rand.Next(867), "potato", "Egypt", rand.Next(3), 2019, rand.Next(12), rand.Next(30));
            }
        }

        public Consignment this[int number]
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
            Console.Write("Vegetable v: ");
            Vegetable v = new Vegetable("Carrot", "France", 2);
            v.print();
            Console.Write("\nCopy of v: ");
            Vegetable v_copy = v;
            v_copy.print();

            Consignment c1 = new Consignment(250, 10, "Cabbage", "USA", 1, 2019, 12, 11);
            Consignment c2 = new Consignment(350, 45, "Cabbage", "USA", 1, 2019, 12, 13);
            Console.WriteLine("\n\nC1: " + c1.ToString() + "\nC2: " + c2.ToString());
            Console.Write("Enter a new price for c2: ");
            c2.Price = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("c1>c2: " + (c1 > c2).ToString());

            Consignment c3 = new Consignment();
            Console.Write("\nDefault Consignment c3: " + c3.ToString());
            c3 = c1 + c2;
            Console.Write("\nc3=c1+c2: ");
            c3.print();

            Warehouse Warehouse = new Warehouse();
            Console.Write("\n\nIndexator: Enter a number(<5)\n");
            int i = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Warehouse[" + i.ToString() + "] : " + Warehouse[i].ToString());

            Vegetable[] arr = new Vegetable[2];
            arr[0] = v;
            arr[1] = c1;
            Console.Write("\n\narr[0] is Vegetable, arr[1] is Consignment\n");
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
