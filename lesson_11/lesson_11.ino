
// Код программы для опыта №11:

// *********************** ЗУММЕР ************************

// Использование пищалки для создания мелодии!

// Зуммер, в комплект вашего набора, является электромеханическим
// компонентом, который можно использовать в качестве источника
// звука. Внутри зуммерa есть катушка, провода и небольшой магнит.
// Когда ток течет через катушку, она становится намагниченной и
// притягивает мембрану к магниту, создавая крошечный "щелчок".
// Когда это происходит с частотой тысячи раз в секунду, создается
// звуковой тон.

// Arduino имеет встроенную команду с именем tone(), которая
// заставляет зуммер издавать звуки различной частоты.
// Эта программа знает частоты определенных нот, что позволяет
// создавать музыкальные мелодии.
// Мы надеемся что полученные знания вам пригодятся в дальнейшем!

// Подсоединяем оборудование:

// Зуммер имеет два контакта. Один из них положительный, другой
// отрицательный. Положительный контактный отмечен символом "+"
// на верхней или нижней части зуммера.

// Подключите положительный вывод к Arduino, цифровой порт 9.
// Обратите внимание, что это должен быть порт ШИМ (PWM).
// Подключите отрицательный вывод к земле.

// Совет: если выводы зуммера не вставляются в плату, попробуйте его
// немного повернуть, чтобы контакты вошли в отверстия по диагонали.

// Этот скетч использует зуммер для воспроизведения мелодий.
// Команда Arduino tone() будет издавать звуки определенной частоты.
// Мы создаем функцию, которая сопоставляет символ нотной гаммы
// ("До-ре-ми-фа...До") соответствующей частоте из следующей таблицы:

// note 	frequency
// c     262 Hz
// d     294 Hz
// e     330 Hz
// f     349 Hz
// g     392 Hz
// a     440 Hz
// b     494 Hz
// C     523 Hz


const int buzzerPin = 9;

// Мы создали массив с нотами, которые хотим воспроизвести,
// измените эти значения, чтобы создать свои мелодии!

// Длина должна равняться общему количеству нот и пауз

const int songLength = 18;

// Обозначение нот представляет собой массив из текстовых символов,
// соответствующим нотам в песне. Пробел означает паузу (пустую ноту)

char notes[] = "cdfda ag cdfdg gf "; // пробелы означают паузы

// Ритм задается массивом из длительности нот и пауз между ними.
// "1" - четвертная нота, "2" - половинная, и т.д.
// Не забывайте, что пробелы должны быть тоже определенной длинны.

int beats[] = {1, 1, 1, 1, 1, 1, 4, 4, 2, 1, 1, 1, 1, 1, 1, 4, 4, 2};

// "tempo" это скорость проигрывания мелодии.
// Для того, чтобы мелодия проигрывалась быстрее, вы
// должны уменьшить следующее значение.

int tempo = 150;


void setup()
{
  pinMode(buzzerPin, OUTPUT);
}


void loop()
{
  int i, duration;

  for (i = 0; i < songLength; i++) // пошаговое воспроизведение
    // из массива
  {
    duration = beats[i] * tempo;  // длительность нот/пауз в ms

    if (notes[i] == ' ')          // если нота отсутствует?
    {
      delay(duration);            // тогда не большая пауза
    }
    else                          // в противном случае играть
    {
      tone(buzzerPin, frequency(notes[i]), duration);
      delay(duration);            // ждать пока проигрывается
    }
    delay(tempo / 10);            // маленькая пауза между нотами
  }

  // Мы хотим, чтобы мелодия проиграла всего один раз, так что здесь остановимся окончательно:
  while (true) {}
  // Если же вы хотите, чтобы мелодия играть снова и снова,
  // Удалить вышеуказанное заявление
}


int frequency(char note)
{
  // Эта функция принимает символ ноты (a-g), и возвращает
  // частоту в Гц для функции tone().

  int i;
  const int numNotes = 8;  // количество хранимых нот

  // Следующие массивы содержат символы нот и соответствующие им
  // частоты. Последний символ "C" (нота "ДО") в верхнем регистре
  // (большая), это сделано для того чтобы отличить ее от первой
  // ноты "с", более низкого тона. Если вы хотите добавить больше
  // нот, вы должны будете использовать уникальный символ для
  // каждой новой ноты.

  // Каждый "char" (символ), мы заключаем в одинарные кавычки.

  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};

  // Теперь мы будем искать во всем массиве, символ ноты и если
  // находим, возвращаем частоту для этой ноты.

  for (i = 0; i < numNotes; i++)  // пошаговый перебор нот
  {
    if (names[i] == note)         // если находим
    {
      return (frequencies[i]);    // возвращаем частоту
    }
  }
  return (0); // Поиск символа не дал результата? Но, необходимо
  // вернуть какое-то значение, так вернем 0.
}
