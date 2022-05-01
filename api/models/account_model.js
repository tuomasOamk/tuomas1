const db = require('../database');
const account = {
  getAll: function(callback) {
    return db.query('select * from account order by id_account desc', callback);
  },
  getById: function(id_account, callback) {
    return db.query('select * from account where id_account=?', [id_account], callback);
  },
  add: function(account, callback) {
    console.log(account);
    return db.query(
      'insert into account (balance, id_account, id_customer) values(?,?,?)',
      [account.balance, account.id_account, account.id_customer],
      callback
    );
  },
  delete: function(id_account, callback) {
    return db.query('delete from account where id_account=?', [id_account], callback);
  },
  update: function(id_account, account, callback) {
    return db.query(
      'update account set balance=?, id_customer=? where id_account=?',
      [account.balance, account.id_customer, id_account],
      callback
    );
  }
};
module.exports = account;