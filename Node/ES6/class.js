
'use strict';

class Polygon {
  constructor(height, weight) {
    this.height = height;
    this.weight = weight;
  }
}

var p = new Polygon(1, 2);
console.log(p.height, p.weight);