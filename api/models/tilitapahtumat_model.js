const db = require('../database');

const tilitapahtumat = {
  getById: function(id, callback) {
    return db.query('select * from tilitapahtumat where idTilitapahtumat=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from tilitapahtumat', callback);
  },
  add: function(tilitapahtumat, callback) {
    return db.query(
      'insert into tilitapahtumat (tilinumero, kortinnumero, päivämäärä_ja_kellonaika, tapahtuma, summa, Tili_idTili) values(?,?,?,?,?,?)',
      [tilitapahtumat.tilinumero, tilitapahtumat.kortinnumero, tilitapahtumat.päivämäärä_ja_kellonaika, tilitapahtumat.tapahtuma, tilitapahtumat.summa, tilitapahtumat.Tili_idTili],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from tilitapahtumat where idTilitapahtumat=?', [id], callback);
  },
  update: function(id, tilitapahtumat, callback) {
    return db.query(
      'update tilitapahtumat set tilinumero=?,kortinnumero=?, päivämäärä_ja_kellonaika=?, tapahtuma=?, summa=?, Tili_idTili=? where idTilitapahtumat=?',
      [tilitapahtumat.tilinumero, tilitapahtumat.kortinnumero, tilitapahtumat.päivämäärä_ja_kellonaika, tilitapahtumat.tapahtuma, tilitapahtumat.summa, tilitapahtumat.Tili_idTili, id],
      callback
    );
  }
};
module.exports = tilitapahtumat;