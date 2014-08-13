<div class="row">
  <div class="col-lg-12">
    <div class="panel panel-info">
      <div class="panel-heading">
        <i class="fa fa-bar-chart fa-fw"></i> 区块统计
      </div>
      <div class="table-responsive">
        <table class="table table-striped table-bordered table-hover">
          <tbody>
            <tr>
              <td colspan="8">
                <a href="{$smarty.server.SCRIPT_NAME}?page={$smarty.request.page}&action={$smarty.request.action}&height={$BLOCKDETAILS.height}&prev=1"><i class="fa fa-chevron-left fa-fw"></i></a>
                <a href="{$smarty.server.SCRIPT_NAME}?page={$smarty.request.page}&action={$smarty.request.action}&height={$BLOCKDETAILS.height}&next=1"><i class="fa fa-chevron-right fa-fw pull-right"></i></a>
              </td>
            </tr>
            <tr class="odd">
              <td>ID</td>
              <td>{$BLOCKDETAILS.id|number_format:"0"|default:"0"}</td>
              <td>Height</td>
              {if ! $GLOBAL.website.blockexplorer.disabled}
              <td><a href="{$GLOBAL.website.blockexplorer.url}{$BLOCKDETAILS.blockhash}" target="_new">{$BLOCKDETAILS.height|number_format:"0"|default:"0"}</a></td>
              {else}
              <td>{$BLOCKDETAILS.height|number_format:"0"|default:"0"}</td>
              {/if}
              <td>币数</td>
              <td>{$BLOCKDETAILS.amount|number_format|default:"0"}</td>
              <td>确认</td>
              <td>{if $BLOCKDETAILS.confirmations >= $GLOBAL.confirmations}
              <font color="green">已确认</font>
              {else if $BLOCKDETAILS.confirmations == -1}
              <font color="red">孤儿</font>
              {else if $BLOCKDETAILS.confirmations == 0}0
              {else}{($GLOBAL.confirmations - $BLOCKDETAILS.confirmations)|default:"0"} 个确认{/if}</td>
            </tr>
            <tr class="even">
              <td>难度</td>
              <td>{$BLOCKDETAILS.difficulty|default:"0"}</td>
              <td>时间</td>
              <td>{$BLOCKDETAILS.time|default:"0"}</td>
              <td>股份</td>
              <td>{$BLOCKDETAILS.shares|number_format:"0"|default:"0"}</td>
              <td>发现者</td>
              <td>{$BLOCKDETAILS.finder|default:"未知"}</td>
            </tr>
          </tbody>
        </table>
      </div>
      <div class="panel-footer">
        <div class="submit_link">
          <form action="{$smarty.server.SCRIPT_NAME}" method="POST" id='search'>
            <input type="hidden" name="page" value="{$smarty.request.page|escape}">
            <input type="hidden" name="action" value="{$smarty.request.action|escape}">
            <input type="text" class="pin" name="search" value="{$smarty.request.height|default:"%"|escape}">
            <input type="submit" value="Search" class="alt_btn">
          </form>
        </div>
      </div>
    </div>
  </div>
</div>
