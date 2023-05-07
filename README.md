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


![image](https://user-images.githubusercontent.com/82521949/236666111-e1179559-9131-4fe8-9c6c-91a96c6e2d29.png)
