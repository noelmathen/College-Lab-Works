    Circle* cptr = new Circle();
    ptr = cptr;
    ptr->draw(); // Runtime binding, calls Circle::draw()

    delete cptr;

    return 0;