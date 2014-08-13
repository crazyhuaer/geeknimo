  <div class="col-lg-6">
    <div class="panel panel-info">
      <div class="panel-heading">
        本轮分币数据
      </div>
      <div class="panel-body">
        <div class="table-responsive">
          <table class="table table-striped table-bordered table-hover {if $ROUNDTRANSACTIONS}datatable{/if}">
            <thead>
              <tr>
                <th>用户名</th>
                <th>类似</th>
                <th>本轮股份</th>
                <th>本轮 %</th>
                <th>获得币数</th>
              </tr>
            </thead>
            <tbody>
{section txs $ROUNDTRANSACTIONS}
              <tr{if $GLOBAL.userdata.username|default:"" == $ROUNDTRANSACTIONS[txs].username} style="background-color:#99EB99;"{else}{/if}>
                <td>{if $ROUNDTRANSACTIONS[txs].is_anonymous|default:"0" == 1 && $GLOBAL.userdata.is_admin|default:"0" == 0}anonymous{else}{$ROUNDTRANSACTIONS[txs].username|default:"unknown"|escape}{/if}</td>
                <td>{$ROUNDTRANSACTIONS[txs].type|default:""}</td>
                <td>{$ROUNDSHARES[$ROUNDTRANSACTIONS[txs].uid].valid|number_format}</td>
                <td>{(( 100 / $BLOCKDETAILS.shares) * $ROUNDSHARES[$ROUNDTRANSACTIONS[txs].uid].valid)|default:"0"|number_format:"2"}</td>
                <td>{$ROUNDTRANSACTIONS[txs].amount|default:"0"|number_format:"8"}</td>
              </tr>
{/section}
            </tbody>
          </table>
        </div>
      </div>
    </div>
  </div>
