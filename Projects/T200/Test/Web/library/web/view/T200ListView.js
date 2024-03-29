const { error, log } = require('../../T200Lib.js');
const T200Error = require('../../T200Error.js');

const T200ViewBase = require('./T200ViewBase.js');


class T200ListView {
    constructor(resource) {
        this.view = new T200ViewBase(resource);
        //
        this._list_url = "";
        this._search_url = "";
        //
        this._change_status_url = "";
        this._delete_url = "";
        this._edit_url = "";
        this._update_url = "";
    }

    /*
    list_buttons() {
        return [
            ['Delete', 'list_hit_delete', 'form', 'list_box', '/admin/note/remove'],
            ['Approve', 'list_hit_approve', 'form', 'list_box', '/admin/note/approve']
        ];
    }


    item_left() {
        return [
            ['Title', 'title', true, '/admin/note/note.html', 'list_title']
        ];
    }

    item_right() {
        return [
            ['Status', 'status', false, '', 'list_status', true, 'id', 'status', 'list_status'],
            ['Username', 'username', true, '', 'list_name', false],
            ['CreateTime', 'create_time', false, '', 'list_time', true, 'time', 'time_title', 'list_time']
        ];
    }
    */

    show(data) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let file = "list/T200ListView.ejs";
    
            /*
            data.item_left = self.item_left();
            data.item_right = self.item_right();
            data.list_buttons = self.list_buttons();
            */
           
            data.list_url = self._list_url;
            data.search_url = self._search_url;
            data.change_status_url = self._change_status_url;
            
            return self.view.render_file(file, data).then(function(result){
                resolve(result);
            }, function(err){
                reject();
            });
        });

        return promise;
    }
}

module.exports = T200ListView;