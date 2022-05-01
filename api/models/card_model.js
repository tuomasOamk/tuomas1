const db = require('../database');
const card = {
  getAll: function(callback) {
    return db.query('select * from card order by id_card desc', callback);
  },
  getById: function(id_card, callback) {
    return db.query('select * from card where id_card=?', [id_card], callback);
  },
  add: function(card, callback) {
    console.log(card);
    return db.query(
      'insert into card (type, locked, id_account) values(?,?,?)',
      [card.type, card.locked, card.id_account],
      callback
    );
  },
  delete: function(id_card, callback) {
    return db.query('delete from card where id_card=?', [id_card], callback);
  },
  update: function(id_card, card, callback) {
    return db.query(
      'update card set type=?,locked=?, id_account=? where id_card=?',
      [card.type, card.locked, card.id_account, id_card],
      callback
    );
  }
};
module.exports = card;