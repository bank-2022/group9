const db = require('../database');

const asiakas = {
  getById: function(id, callback) {
    return db.query('select * from asiakas where idAsiakas=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from asiakas', callback);
  },
  add: function(asiakas, callback) {
    return db.query(
      'insert into asiakas (tunnus,nimi,lähiosoite, puhelinnumero) values(?,?,?,?)',
      [asiakas.tunnus, asiakas.nimi, asiakas.lähiosoite, asiakas.puhelinnumero],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from asiakas where idAsiakas=?', [id], callback);
  },
  update: function(id, asiakas, callback) {
    return db.query(
      'update asiakas set tunnus=?,nimi=?, lähiosoite=?, puhelinnumero=? where idAsiakas=?',
      [asiakas.tunnus, asiakas.nimi, asiakas.lähiosoite, asiakas.puhelinnumero, id],
      callback
    );
  }
};
module.exports = asiakas;