using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class SqlDefaultValueAttribute : Attribute
{
    public SqlDefaultValueAttribute(string defaultValue)
    {
        DefaultValue = defaultValue;
    }

    public string DefaultValue { get; set; }
}