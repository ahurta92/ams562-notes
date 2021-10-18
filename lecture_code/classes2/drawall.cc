void Smiley::draw() const {
  Circle::draw();
  for (auto p : eyes)
    p->draw();
  mouth->draw();
}
