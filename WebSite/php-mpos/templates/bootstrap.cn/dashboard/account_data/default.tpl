  <div class="col-lg-4">
    <div class="panel panel-info">
      <div class="panel-heading">
        <h4 class="panel-title"><i class="fa fa-user-md fa-fw"></i> 账 户 信 息</h4>
      </div>
      <div class="panel-body no-padding">
        <table class="table table-bordered table-hover table-striped">
          <tr>
            <td colspan="2">
    {if $GLOBAL.userdata.no_fees}
            你的矿工免手续费用
    {else if $GLOBAL.fees > 0}
            本池收取 <font color="orange">{if $GLOBAL.fees < 0.0001}{$GLOBAL.fees|escape|number_format:"8"}{else}{$GLOBAL.fees|escape}{/if}%</font> 为矿池服务器运作费用.
    {else}
            本矿池免任何手续费用
    {/if}
    {if $GLOBAL.userdata.donate_percent > 0}
            你捐赠 <font color="green">{$GLOBAL.userdata.donate_percent|escape}%</font>.
    {else}
            你没有设置捐赠,我要 <a href="{$smarty.server.SCRIPT_NAME}?page=account&action=edit">捐赠</a>.
    {/if}
            </td>
          </tr>
        </table>
        <table class="table table-bordered table-hover table-striped">
          <thead>
            <tr><th colspan="2">{$GLOBAL.config.currency} 账户未支付余额</th></tr>
          </thead>
          <tbody>
            <tr>
              <th>已确认</th>
              <th>
                <span class="label label-success pull-right bigfont" id="b-confirmed">{$GLOBAL.userdata.balance.confirmed|number_format:"6"}</span>
              </th>
            </tr>
            <tr>
              <th>未成熟</th>
              <th>
                <span class="label label-warning pull-right bigfont" id="b-unconfirmed">{$GLOBAL.userdata.balance.unconfirmed|number_format:"6"}</span>
              </th>
            </tr>
          </tbody>
        </table>
      </div>
    </div>
  </div>
