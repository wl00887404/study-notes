#include <iostream>
#include <string>

using namespace std;

/**
 * NOTE:
 *   在 C++ 中，class 和 struct
 *   之間的主要區別在於默認的存取權。除此之外，它們幾乎是相同的。
 *
 *   class 默認是 private 繼承，struct 默認是 public 繼承
 */

void arrayTest() {
  int array[] = {1, 2, 3};

  cout << "array.length: " << sizeof(array) / sizeof(array)[0] << endl;

  cout << "array begin: " << begin(array) << endl;
  cout << "array end: " << end(array) << endl;
  cout << "array.length: " << end(array) - begin(array) << endl;
}

struct MyStruct {
  int a = 1;

 private:
  int b = 2;
};

void structTest() {
  MyStruct myStruct;
  myStruct.a = 3;  // OK
  myStruct.b = 4;  // ERROR
}

class GrandParent {
  // 可以公開存取，繼承的 class 可以存取
 public:
  int a = 1;

  // 不能公開存取，繼承的 class 不能存取
 private:
  int b = 2;

  // 不能公開存取，繼承的 class 可以存取
 protected:
  int c = 3;
};

class PublicParent : public GrandParent {
  void test1() {
    cout << a << endl;
    cout << b << endl;  // ERROR
    cout << c << endl;
  }
};

class PrivateParent : private GrandParent {
  void test1() {
    cout << a << endl;
    cout << b << endl;  // ERROR
    cout << c << endl;
  }
};

class ProtectedParent : protected GrandParent {
  void test1() {
    cout << a << endl;
    cout << b << endl;  // ERROR
    cout << c << endl;
  }
};

void parentTest() {
  PublicParent publicParent;
  PrivateParent privateParent;
  ProtectedParent protectedParent;

  // NOTE: public + public inherit = public
  publicParent.a = 3;  // OK
  // NOTE: private + public inherit = private
  publicParent.b = 4;  // ERROR
  // NOTE: protected + public inherit = protected
  publicParent.c = 5;  // ERROR

  // NOTE: public + private inherit = private
  privateParent.a = 3;  // ERROR
  // NOTE: private + private inherit = private
  privateParent.b = 4;  // ERROR
  // NOTE: protected + private inherit = private
  privateParent.c = 5;  // ERROR

  // NOTE: public + protected inherit = protected
  protectedParent.a = 3;  // ERROR
  // NOTE: private + protected inherit = private
  protectedParent.b = 4;  // ERROR
  // NOTE: protected + protected inherit = protected
  protectedParent.c = 5;  // ERROR
}

class PublicChild : public PublicParent {
  void test2() {
    cout << a << endl;  // OK
    cout << b << endl;  // ERROR
    cout << c << endl;  // OK
  }
};

class PrivateChild : private PrivateParent {
  void test2() {
    cout << a << endl;  // ERROR
    cout << b << endl;  // ERROR
    cout << c << endl;  // ERROR
  }
};

class ProtectedChild : protected ProtectedParent {
  void test2() {
    cout << a << endl;  // OK
    cout << b << endl;  // ERROR
    cout << c << endl;  // OK
  }
};

void childTest() {
  PublicChild publicChild;
  PrivateChild privateChild;
  ProtectedChild protectedChild;

  // NOTE: public + public inherit = public
  publicChild.a = 3;  // OK
  // NOTE: private + public inherit = private
  publicChild.b = 4;  // ERROR
  // NOTE: protected + public inherit = protected
  publicChild.c = 5;  // ERROR

  // NOTE: private + private inherit = private
  privateChild.a = 3;  // ERROR
  // NOTE: private + private inherit = private
  privateChild.b = 4;  // ERROR
  // NOTE: private + private inherit = private
  privateChild.c = 5;  // ERROR

  // NOTE: protected + protected inherit = protected
  protectedChild.a = 3;  // ERROR
  // NOTE: private + protected inherit = private
  protectedChild.b = 4;  // ERROR
  // NOTE: protected + protected inherit = protected
  protectedChild.c = 5;  // ERROR
}

/**
 * NOTE:
 *   public + public inherit = public
 *   public + private inherit = private
 *   public + protected inherit = protected
 *
 *   private + public inherit = private
 *   private + private inherit = private
 *   private + protected inherit = private
 *
 *   protected + public inherit = protected
 *   protected + private inherit = private
 *   protected + protected inherit = protected
 */

/**
 * 參考良葛格的 [C++
 * 教學](https://openhome.cc/Gossip/CppGossip/HideMemberFunction.html) 可以使用
 * using parentProperty 繼承跟 parent 一樣權限的 property
 *
 */

class Role {
  string name;  // 角色名稱
  int level;    // 角色等級
  int hp;       // 角色血量

 public:
  Role(string name, int level, int hp) {
    this->name = name;
    this->level = level;
    this->hp = hp;
  }
  // NOTE: 複製建構式
  Role(const Role &lt) {
    cout << lt.name << " 被複製了" << endl;
    this->name = lt.name;
    this->level = lt.level;
    this->hp = lt.hp;
  }
  virtual void fight() { cout << "沒有定義的攻擊" << endl; }

  // NOTE: const 放後面修飾，表示此 function 是純函式，不能修改 this
  string to_string() const {
    return "(" + this->name + ", " + std::to_string(this->level) + ", " +
           std::to_string(this->hp) + ")";
  };

  virtual ~Role() = default;  // NOTE: 讓解構式也可以多載

 protected:
  int foo;
  int bar;
};

class SwordMan : public Role {
 public:
  using Role::Role;  // NOTE: 使用 Role 的建構式

  void fight() { cout << "揮劍攻擊" << endl; }

  string to_string() {
    // NOTE: C++ 可以多重繼承，所以沒有 Super
    return "SwordMan" + Role::to_string();
  };
};

class Magician : public Role {
 public:
  using Role::Role;
  // NOTE: 定義 Role 的別名為 super
  using super = Role;

  void fight() { cout << "魔法攻擊" << endl; }

  void cure() { cout << "魔法治療" << endl; }

  string to_string() {
    // NOTE: 運用別名的假 super
    return "Magician" + super::to_string();
  };
};

class PrivateRole : private Role {
 public:
  using Role::Role;
  // NOTE: using 可以將 protected 變成 public （雖然不知道這樣能幹嘛）
  using Role::foo;
};

void PolymorphismTest() {
  SwordMan swordMan = SwordMan("nico", 100, 100);
  /**
   * NOTE: 這樣操作多型是失敗的
   *   因為這個寫法是複製一個 swordMan 給 role0
   *   必須使用指標指標才行
   */
  Role role0 = swordMan;
  cout << "role0.to_string(): " << role0.to_string() << endl;

  Role *role1 = &swordMan;
  // NOTE: 想要多型失敗，要使用 virtual 關鍵字
  cout << role1->to_string() << endl;

  role1->fight();

  PrivateRole privateRole("max", 100, 100);
  privateRole.foo = 1;
}

int main() {
  PolymorphismTest();
  return 0;
}