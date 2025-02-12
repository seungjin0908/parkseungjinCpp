namespace WebAPI
{
    public class WeatherForecast
    {
        public DateOnly Date { get; set; }

        public int TemperatureC { get; set; }

        public int TemperatureF => 32 + (int)(TemperatureC / 0.5556);

        public string? Summary { get; set; }
    }


    public class Test
    {
        public int A { get; set; }
        public int B { get; set; }
        public int C { get; set; }
    }

}
