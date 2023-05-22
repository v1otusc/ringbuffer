class Nocopyable {
 public:
  Nocopyable(){};
  virtual ~Nocopyable(){};

  Nocopyable(const Nocopyable &) = delete;
  Nocopyable &operator=(const Nocopyable &) = delete;
};