/*
 * Набор для экспериментов MaxKit 01
 * Код программы для опыта №1: sketch 01
 *
 * МИГАЮЩИЙ СВЕТОДИОД
 *
 * Написано для сайта "Полный комплект" http://maxkit.ru
 *
 *
 * Помощь сообщества Arduino.
 * Посетите сайт http://www.arduino.cc
 *
 *
 * МИГАЮЩИЙ СВЕТОДИОД
 *
 * Программа включает светодиод на одну секунду, затем
 * выключает, ждет секунду и снова включает, этот
 * процесс повторяется снова и снова и снова...
 *
 * Подключение оборудования:
 *
 * В большинстве плат Arduino уже есть встроенный светодиод и
 * резистор подсоединенные к порту 13 (pin 13), поэтому обходимости
 * собирать схему отдельно нет, но..
 *
 * Но если вы хотите понять и почувствовать, как это работает,
 * следующие инструкции для вас:
 *
 * Подсоедините положительный вывод светодиода (длинная ножка) к
 * плате Arduino - порт 13 (pin 13), или другой, но тогда не забудьте
 * подправить код программы (скетча).
 *
 * Подсоедините отрицательный (минусовой) вывод светодиода (короткая
 * ножка) к резистору 330 Ом (или другой от 220 - до 560 Ом). Цветовые
 * полоски на резисторе 330 Ом - оранж.-оранж.-коричн.. Другой конец
 * резистора подсоедините к минусу питания (GND).
 *
 * pin 13 _____ + LED - _____ 330 Ohm _____ GND
 *
 * (Мы всегда будем включать резистор между Arduino и светодиодом,
 * это необходимо для защиты светодиода от выгорания, из за слишком
 * большого тока).
 *
 *
 *
 * Этот sketch был написан SparkFun Electronics,
 * Переведен специально для сайта http://maxkit.ru
 * 01 февраля 2015г.
 *
*/


// Добро пожаловать в Arduino!

// Если это устройство совершенно не знакомо вам, и в описаниях
// встречаются не знакомые термины, не волнуйтесь, мы к ним
// обязательно вернёмся и подробно опишим что и как  работает.

// Arduino представляет из себя "миниатюрный компьютер", который
// работает по программе, называемой "scetche" - "скетчи" (зарисовки).
// Sketches, это текстовые файлы, написанные с помощью текстового
// редактора, один из таких скетчей Вы читаете прямо сейчас. 

// В скетчах есть компьютерный код, а есть "коментарии", которые
// объясняют, что делает этот код. В скетче, открытом в программе
// "Arduino IDE", коментарии и код будут иметь разные цвета,
// так что вы сможете легко отличить их друг от друга. 

// Коментарий начинается с символа "//" (двойная косая), всё что идет
// после него на одной строке это коментарий. Arduino во время подготовки
// программы игнорирует все коментарии, попросту говоря - отбрасывает,
// оставляя чистый код.

/* 
   Таким способом (с помощью косой черты и звёздочки делается коментарий
   сразу для нескольких строк.
*/

// "Функцией" - назвается блок кода, или набор команд, к которым может,
// время от времени обращаться ваша программа. Много полезных функций
// уже написанны для Arduino. Другие, новые Вы напишете для себя сами.

// У всех скетчей Arduino ДОЛЖНО быть две определенных функции,
// названные "setup()" и "loop()" (setup - в переводе на руский - установка,
// а loop - петля). Arduino запускает эти функции автоматически, когда
// стартует, при подачи питания, и если Вы нажимаете кнопку сброса (RESET).
// Как правило Вы сами будете наполнять эти функция своим собственным кодом.
// Давайте начнем!

// Функция setup() выполняется в начале, когда стартует программа, а это 
// значит, что Вы можете использовать ее для тех условий которые необходимо
// выполнить именно в начале, или всего один раз:

void setup()
{
  // У Arduino есть 13 цифровых портов ввода/вывода. Еще эти порты
  // можно называть пинами (от англ. pin). Эти порты могут работать как
  // входами так и выходами, в зависимости от того как мы запрограммируем.
  // Настраиваются они с помощью встроенной функцией pinMode().  

  // Функция pinMode() получает два значения, которые Вы передаете ей
  // в круглых скобках, сразу после имени функции. Первое это цифра - номер
  // порта, второе - слово INPUT(ВХОД) или OUTPUT(ВЫХОД).
  
  // Здесь мы настроим pin 13 (соединенный со светодиодом), как исходящий.
  // Мы делаем это, для того чтобы "послать" напряжение Arduino к СВЕТОДИОДУ.

  pinMode(13, OUTPUT);

  // Между прочим, Arduino предлагает множество полезных встроенных
  // функций как эта. Подробную информацию обо всех функциях Вы можете
  // найти на веб-сайте Arduino: http://arduino.cc/en/Reference (Eng.)  
}

// После того как функция setup() отработает, начнет выполнение функция loop().
// Она выполняется много раз по кругу, пока Вы не выключите или не
// перезагрузите Arduino. Это то место где, обычно, живет Ваша программа.

void loop()
{

  // 13 цифровых портов Arduino очень могущественны, они могут работать как
  // входящими, так и исходящими, могут быть ВКЛ., а могут быть ВЫКЛ, но всегда
  // будут либо 5 Вольт "HIGH" (ВЫСОКИМ), либо 0 Вольт "LOW" (НИЗКИМ).

  // Поскольку у нас есть светодиод, подсоединенный к порту 13, мы можем
  // выдадать в порт сигнал "HIGH" (5 Вольт), тогда светодиод засветится. Если мы
  // выдадим в порт сигнал "LOW" (0 Вольт) светодиод, соответственно,
  // светится перестанет, из за отсутствия напряжения.

  // Функция digitalWrite() является встроенной функцией, которую мы используем,
  // для того чтобы заставить Arduino выдать в порт ВЫСОКИЙ или НИЗКИЙ сигнал.
  // В скобках функция получает два параметра - номер порта, и сигнал 5 Вольт (HIGH),
  // или 0 Вольт (LOW):

  digitalWrite(13, HIGH);   // Включить светодиод

  // Функция delay() (задержка) является функцией "паузы" для определенного
  // количества времени. Параметр в скобках как раз и определят это время в
  // миллисекундах. 1000 миллисекунд - это одна секунда, поэтому если
  // Вы пишите delay(1000), то она сделает паузу в одну секунду:
  
  delay(1000);              // Ожидание - 1 секунда
  
  digitalWrite(13, LOW);    // Выключить светодиод
  
  delay(1000);              // Ожидание - 1 секунда

  // Всё вместе, выше написанный код выглядит следующим образом:
  // Выключить светодиод, подождать секунду, включить светодиод
  // снова подождать секунду и снова выключить.

  // Когда компьютер доходит до конца функции loop(), он возвращается
  // к её началу. и снова начинает выполнение программы, и светодиод
  // будет вкючаться и выключаться, снова и снова!

  // Попробуйте изменить 1000 на другие значения в функции delay(1000) и
  // посмотрите, как меняется время задержки. Меньшие значения делают
  // выполнение фунции loop() быстрее. (Почему?)
}
