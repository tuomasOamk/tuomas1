const db = require('../database');
const transaction = {
  getAll: function(callback) {
    return db.query('select * from transaction order by id_transaction desc', callback);
  },
  getById: function(id_transaction, callback) {
    return db.query('select * from transaction where id_transaction=?', [id_transaction], callback);
  },
  add: function(transaction, callback) {
    console.log(transaction);
    return db.query(
      'insert into transaction (sum, id_account,id_card) values(?,?,?)',
      [transaction.sum, transaction.id_account,transaction.id_card],
      callback
    );
  },
  delete: function(id_transaction, callback) {
    return db.query('delete from transaction where id_transaction=?', [id_transaction], callback);
  },
  update: function(id_transaction, transaction, callback) {
    return db.query(
      'update transaction set sum=?,id_account=?,id_card=? where id_transaction=?',
      [transaction.sum, transaction.id_account, transaction.id_card, id_transaction],
      callback
    );
  }
};
module.exports = transaction;