// Declare overriding functions override.

class Base {
  virtual void mf1() const {}
  virtual void mf2(int x) {}
  virtual void mf3() & {}
  virtual void mf4() const {}
};
class Derivered : public Base {
  // virtual void mf1();
  // virtual void mf2(unsigned int x);
  // virtual void mf3() &&;
  // void mf4() const;
  void mf1() const override {}
  void mf2(int x) override {}
  void mf3() & override {}
  void mf4() const override {}
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
