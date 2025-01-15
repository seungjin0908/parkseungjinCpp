using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_Day39
{
    //Try - Catch - Finally
    public class App05
    {
        public void Run()
        {
            //C++과 비슷합니다
            // try안의 내용을 순차적으로 실행합니다.
            // 그러다가 에러가 발생하면
            // catch로 넘어갑니다.
            // catch문 안에서는 try에서 생긴 이슈를 롤백
            // 
            // finally는?
            // try로 가나, catch로 가나
            // 어디로 가던지 무조건 실행하는 구문


            Console.WriteLine("Try - Catch문 실행.");
            try
            {

                int b = int.Parse(Console.ReadLine());

                if( b == 1)
                {
                    throw new SBSException(EErrorCode.ServerException, "b == 1");
                }
            }
            catch (DivideByZeroException ex)
            {
                Console.WriteLine("0으로 나눴구나..");
            }
            catch (SBSException ex)
            {
                // 팝업창 소환
                Console.WriteLine(ex.Message);
                Console.WriteLine(ex.ErrorCode);
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }
            finally
            {
                Console.WriteLine("Finally 실행");
            }

            Console.WriteLine("끝");
        }
    }


    public enum EErrorCode
    {
        OK,
        ServerException,
        DBException
    }


    public class SBSException : Exception
    {
        public SBSException() { }

        public SBSException(EErrorCode errorCode, string message)
            : base (message)
        {
            _errorCode = errorCode;
        }

        EErrorCode _errorCode;

        public EErrorCode ErrorCode => _errorCode;
    }
}
