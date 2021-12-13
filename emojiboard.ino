// Secret santa for Zack
// James Long

#include "USBHost_t36.h"
#define KEYBOARD_INTERFACE 0

#define BACKSPACE_KEY 0x7F

USBHost myusb;
KeyboardController keyboard1(myusb);

void setup()
{
  myusb.begin();
  randomSeed(analogRead(0));
  Keyboard.begin();
  keyboard1.attachPress(OnPress);
}

void loop()
{
  myusb.Task();
}

void OnPress(int key)
{
  Serial.printf("key %i\n", key);

  if (key == BACKSPACE_KEY) {
    Keyboard.write(key);
    return;
  }

  int randNumber = random(150);

  // sorry zack
  if (randNumber == 0) {
    Keyboard.write(":santa: :jl: :jnc-spin: :vasko-the-legend: :tshirt:");
    return;
  } else if (randNumber <= 4) {
    Keyboard.write(":eggplant:");
    return;
  }

  if (key >= 65 && key < 91) { key += 32; } // I am too lazy to implement raw onpress logic instead
  
  const char *mappedEmoji;
  
  switch(key) {
    // A-Z keys - standard emoji
    case 'q': mappedEmoji = ":tada:"; break;
    case 'w': mappedEmoji = ":two:"; break;
    case 'e': mappedEmoji = ":game_die:"; break;
    case 'r': mappedEmoji = ":crumpet:"; break;
    case 't': mappedEmoji = ":leafy_green:"; break;
    case 'y': mappedEmoji = ":chicken:"; break;
    case 'u': mappedEmoji = ":cow:"; break;
    case 'i': mappedEmoji = ":pig:"; break;
    case 'o': mappedEmoji = ":sheep:"; break;
    case 'p': mappedEmoji = ":turkey:"; break;
    case 'a': mappedEmoji = ":corn:"; break;
    case 's': mappedEmoji = ":burrito:"; break;
    case 'd': mappedEmoji = ":key:"; break;
    case 'f': mappedEmoji = ":baby:"; break;
    case 'g': mappedEmoji = ":mask:"; break;
    case 'h': mappedEmoji = ":no:"; break;
    case 'j': mappedEmoji = ":ski:"; break;
    case 'k': mappedEmoji = ":bangbang:"; break;
    case 'l': mappedEmoji = ":end:"; break;
    case 'z': mappedEmoji = ":potato:"; break;
    case 'x': mappedEmoji = ":flag-lk:"; break;
    case 'c': mappedEmoji = ":motorway:"; break;
    case 'v': mappedEmoji = ":bowl_with_spoon"; break;
    case 'b': mappedEmoji = ":cat:"; break;
    case 'n': mappedEmoji = ":shoe:"; break;
    case 'm': mappedEmoji = ":curry:"; break;

    // F1-F5 - pre-made meals
    case KEYD_F1: mappedEmoji = ":tada: :two: :game_die:"; break;
    case KEYD_F2: mappedEmoji = ":sheep: :key: :baby:"; break;
    case KEYD_F3: mappedEmoji = ":tada: :calendar: - :chicken: :corn: (:heavy_minus_sign: :end:) :mask: (:x: :ski:)"; break;
    case KEYD_F4: mappedEmoji = ":flag-lk: :motorway: :bowl_with_spoon:"; break;
    case KEYD_F5: mappedEmoji = ":cat: :shoe: :curry:"; break;

    // F6-F12 - date/time
    case KEYD_F6: mappedEmoji = ":calendar:"; break;
    case KEYD_F7: mappedEmoji = ":clock12:"; break;
    case KEYD_F8: mappedEmoji = ":clock1230:"; break;
    case KEYD_F9: mappedEmoji = ":clock1:"; break;
    case KEYD_F10: mappedEmoji = ":clock430:"; break;
    case KEYD_F11: mappedEmoji = ":clock5:"; break;
    case KEYD_F12: mappedEmoji = ":clock530:"; break;

    // 0-9 - map to :one:, etc
    case '0': mappedEmoji = ":zero:"; break;
    case '1': mappedEmoji = ":one:"; break;
    case '2': mappedEmoji = ":two:"; break;
    case '3': mappedEmoji = ":three:"; break;
    case '4': mappedEmoji = ":four:"; break;
    case '5': mappedEmoji = ":five:"; break;
    case '6': mappedEmoji = ":six:"; break;
    case '7': mappedEmoji = ":seven:"; break;
    case '8': mappedEmoji = ":eight:"; break;
    case '9': mappedEmoji = ":nine:"; break;

    // Random
    case '[': mappedEmoji = ":dango:"; break;
    case ']': mappedEmoji = ":gun:"; break;
    case ';': mappedEmoji = ":rice:"; break;
    case '\'': mappedEmoji = ":x:"; break;
    case '#': case 0: mappedEmoji = ":shh:"; break; // weird thing on my logitech keyboard, might be global
    case ',': mappedEmoji = ":roll_of_paper:"; break;
    case '.': mappedEmoji = ":heavy_minus_sign:"; break;
    case '/': mappedEmoji = ":sadseal:"; break;
    case KEYD_INSERT: mappedEmoji = ":netcraft-rotate:"; break;
    case KEYD_HOME: mappedEmoji = ":netcraft-love:"; break;
    case 10: mappedEmoji = ":superhero:"; break; // enter key
    case KEYD_DELETE: mappedEmoji = ":rip:"; break;
    case 9: mappedEmoji = ":thunk:"; break; // tab key
    case '-': mappedEmoji = ":galaxy_brain:"; break;
    case '=': mappedEmoji = ":runner:"; break;
    case 27: mappedEmoji = ":coronavirus:"; break;
    case '`': mappedEmoji = ":pray:"; break;
    case KEYD_PAGE_UP: mappedEmoji = ":party-parrot:"; break;
    case KEYD_PAGE_DOWN: mappedEmoji = ":bikeshed:"; break;

    // some momentos
    case ' ': mappedEmoji = ":jl:"; break;
    case KEYD_UP: mappedEmoji = ":jnc-spin:"; break;
    case KEYD_LEFT: mappedEmoji = ":super_sains:"; break;
    case KEYD_RIGHT: mappedEmoji = ":vasko-the-legend:"; break;
    case KEYD_DOWN: mappedEmoji = ":tshirt:"; break;
    

    // poo
    default: mappedEmoji = ":poo:";
  }
  
  Keyboard.write(mappedEmoji);
}
