#ifndef __NOCOPYABLE_H__
#define __NOCOPYABLE_H__

class Nocopyable {
 public:
  Nocopyable(){};
  virtual ~Nocopyable(){};

  Nocopyable(const Nocopyable &) = delete;
  Nocopyable &operator=(const Nocopyable &) = delete;
};

#endif // __NOCOPYABLE_H__
