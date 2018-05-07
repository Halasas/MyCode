var object = function(name) {
    this.toString() {
        return name.toString();
    }
}

var expression = function(name) {
   this.toString() {
        return name.toString();
    }
}

function Variable(name) {
    this.__proto__ = Object;
    this.evaluate = function(x,y,z) {
        if(name === 'x')
            return x;
        if(name === 'y')
            return y;
        if(name === 'z')
            return z;
    }
}

function Const(value) {
    this.evaluate = function(x,y,z) {
        return value;
    }
    this.toString = function() {
        return value.toString();
    }
}

function pow(x, n) {
  if (n == 1) {
    return x;
  }

  var result = x * pow(x, n - 1);
  return result;
}

