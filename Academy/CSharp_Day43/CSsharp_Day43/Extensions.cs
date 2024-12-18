using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//이름은 마음대로 바꿔도돼요.
public static partial class Extensions
{
    public static int MyFunction(this string str)
    {
        return str.Count();
    }

    public static bool IsBetween(this int myNumber, int num1, int num2)
    {
        if(num2 < num1)
        {
            int temp = num2;
            num2 = num1;
            num1 = temp;
        }

        if(num1 <= myNumber && myNumber <= num2)
        {
            return true;
        }

        return false;
    }
}