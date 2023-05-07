# SaberInteractiveTest
# Task 1

 Реализуйте функции сериализации и десериализации двусвязного списка, заданного следующим образом:
    
    class ListNode
    {
    
        public ListNode Prev;
        public ListNode Next;
        public ListNode Rand; // произвольный элемент внутри списка
        public string Data;
    }


    class ListRand
    {
        public ListNode Head;
        public ListNode Tail;
        public int Count;

        public void Serialize(FileStream s)
        {
        }

        public void Deserialize(FileStream s)
        {
        }
    }



Алгоритмическая сложность решения должна быть меньше квадратичной.
Нельзя добавлять новые поля в исходные классы ListNode, ListRand
Для выполнения задания можно использовать любой общеиспользуемый язык.
Тест нужно выполнить без использования библиотек/стандартных средств сериализации.

# Task2

Напишите ИИ для противника используя BhvTree (достаточно нарисовать схему, реализация в каком-либо из движков не требуется).
Солдат - сущность, которая может стрелять, отправиться в указанную точку и ждать.
Солдат проводит патруль по зацикленному маршруту по точкам А и Б
По прибытии на точку солдат останавливается на 5 минут в ожидании врага. Если за 5 минут враг не появился, солдат идет на следующую точку.
Если враг обнаружен, солдат стреляет в него с паузой в 1 секунду между каждым выстрелом


Начало стрельбы независимо от того, прибыл солдат на точку или нет
![image](https://user-images.githubusercontent.com/82521949/236664614-f2531881-908a-435b-a245-dbb07b57a94b.png)



Начало стрельбы только по прибытию на точку
![image](https://user-images.githubusercontent.com/82521949/236665140-e229ad4b-e3d5-426c-be3f-d559ec269d47.png)

