using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_Day39
{
    // 인터페이스
    public class App04
    {
        public void Run()
        {
            ICreature creature1 = new Hero();
            ICreature creature2 = new Enemy();


            //매니저 코드에서

            List<ICreature> list = new List<ICreature>();
            list.Add(creature1);
            list.Add(creature2);

            // 매니저에서는 Creature를 들고있는것도 아닙니다.
            // 커플링이 많이 깨지게 됩니다.
            // 이 코드를 쓰는데, 다른 클래스가 필요한경우
            //  커플링의경우 많아지면, 코드결합도가 높아지는거라
            //  장기적인 측면으로 봤을떄 유지보수가 힘듭니다.

            //반복문 C#에서 하나 추가됩니다.
            foreach (ICreature creature in list)
            {
                creature.OnDamaged(creature1);
            }

            //for ( ICreature creature : list)
            //{

            //}
        }
    }

    // 아군캐릭터
    public class Hero : Creature
    {
        private int _classType = 0; // 전사, 마법사, 도적
    }

    // 적군몬스터 
    public class Enemy : Creature
    {
        private bool _isFlying = false; // 지상유닛, 공중유닛
    }

    // 전투하는 걸어다니는 애
    public class Creature : ICreature
    {
        protected int _id;
        protected float _hp;
        protected float _attack;

        public int Id => _id;
        public float HP => _hp;
        public float Attack => _attack;

        void ICreature.OnDamaged(ICreature attacker)
        {
            this._hp -= attacker.Attack;

            // 인터페이스나, 상속을 사용하였을떄 쓰이는 연산자
            // is as 연산자

            if(attacker is Hero)
            {
                //attacker가 hero인지 알고 싶을때
            }

            // as 연산자
            Hero? hero = attacker as Hero;
            if (hero != null)
            {
                //attcker는 hero다.
            }

            Hero hero1 = (Hero)attacker;
            // 온애가 Hero가 아니면
            // Exception이 나와요.

            //is 연산자는 결과가 boolean으로 나옵니다.
            //as 연산자는 결과가 레퍼런스로 나옵니다.
            //      있으면 레퍼런스 없으면 null이 나옵니다.

        }
    }
    
    // 인터페이스는 함수만 가지고있는 자료형
    // 추가설명으로는 객체가 될 수 없습니다.
    public interface ICreature
    {
        public int Id { get; }
        public float HP { get; }
        public float Attack { get; }

        void OnDamaged(ICreature attacker);
    }
}
