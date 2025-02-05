using Microsoft.EntityFrameworkCore.Metadata.Builders;
using Microsoft.EntityFrameworkCore.Metadata.Conventions;
using Microsoft.EntityFrameworkCore.Metadata.Conventions.Infrastructure;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;


public class SqlDefaultValueConvention
    : PropertyAttributeConventionBase<SqlDefaultValueAttribute>
{
    public SqlDefaultValueConvention(ProviderConventionSetBuilderDependencies dependencies)
        : base(dependencies)
    {
    }

    protected override void ProcessPropertyAdded(
        IConventionComplexPropertyBuilder propertyBuilder,
        SqlDefaultValueAttribute attribute,
        MemberInfo clrMember,
        IConventionContext context)
    {
        propertyBuilder.HasDefaultValueSql(attribute.DefaultValue);
    }
}

